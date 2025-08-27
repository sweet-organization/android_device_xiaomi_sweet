/*
 * Copyright (C) 2021 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <unistd.h>
#include <vector>
#include <string>
#include <android-base/properties.h>

#include "libinit_utils.h"
#include "libinit_variant.h"

using android::base::GetProperty;

#define HWC_PROP "ro.boot.hwc"
#define SKU_PROP "ro.boot.product.hardware.sku"

void search_variant(const std::vector<variant_info_t> &variants) {
    std::string hwc_value = GetProperty(HWC_PROP, "");
    std::string sku_value = GetProperty(SKU_PROP, "");

    for (const auto &v : variants) {
        if ((v.hwc_value.empty() || v.hwc_value == hwc_value) &&
            (v.sku_value.empty() || v.sku_value == sku_value)) {
            set_variant_props(v);
            break;
        }
    }
}

void set_variant_props(const variant_info_t &variant) {
    auto marketname = !variant.marketname.empty() ? variant.marketname : variant.model;

    set_ro_build_prop("brand", variant.brand, true);
    set_ro_build_prop("device", variant.device, true);
    set_ro_build_prop("marketname", marketname, true);
    set_ro_build_prop("model", variant.model, true);
    property_override("vendor.usb.product_string", marketname, true);
    property_override("persist.sys.device_camera_info_rear", variant.cam_info.c_str());

    if (access("/system/bin/recovery", F_OK) != 0) {
        property_override("bluetooth.device.default_name", marketname, true);
        set_ro_build_prop("fingerprint", variant.build_fingerprint);
        property_override("ro.bootimage.build.fingerprint", variant.build_fingerprint);

        property_override("ro.build.description",
                          fingerprint_to_description(variant.build_fingerprint));
    }
}
