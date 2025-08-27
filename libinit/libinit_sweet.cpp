/*
 * Copyright (C) 2021 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <libinit_dalvik_heap.h>
#include <libinit_variant.h>

#include "vendor_init.h"

static const variant_info_t sweet_info = {
    .hwc_value = "GLOBAL",
    .sku_value = "",

    .brand = "Redmi",
    .device = "sweet",
    .marketname = "Redmi Note 10 Pro",
    .model = "M2101K6G",
    .build_fingerprint = "Redmi/sweet_global/sweet:13/RKQ1.210614.002/V14.0.9.0.TKFMIXM:user/release-keys",
    .cam_info = "108,8,5,2",
};

static const variant_info_t sweetjp_info = {
    .hwc_value = "JAPAN",
    .sku_value = "",

    .brand = "Redmi",
    .device = "sweet",
    .marketname = "Redmi Note 10 Pro",
    .model = "M2101K6R",
    .build_fingerprint = "Redmi/sweet_global/sweet:13/RKQ1.210614.002/V14.0.9.0.TKFMIXM:user/release-keys",
    .cam_info = "108,8,5,2",
};

static const variant_info_t sweetin_info = {
    .hwc_value = "INDIA",
    .sku_value = "std",

    .brand = "Redmi",
    .device = "sweetin",
    .marketname = "Redmi Note 10 Pro",
    .model = "M2101K6P",
    .build_fingerprint = "Redmi/sweetin/sweetin:13/RKQ1.210614.002/V14.0.1.0.TKFINXM:user/release-keys",
    .cam_info = "64,8,5,2",
};

static const variant_info_t sweetinpro_info = {
    .hwc_value = "INDIA",
    .sku_value = "pro",

    .brand = "Redmi",
    .device = "sweetin",
    .marketname = "Redmi Note 10 Pro Max",
    .model = "M2101K6I",
    .build_fingerprint = "Redmi/sweetinpro/sweetin:13/RKQ1.210614.002/V14.0.1.0.TKFINXM:user/release-keys",
    .cam_info = "108,8,5,2",
};

static const std::vector<variant_info_t> variants = {
    sweet_info,
    sweetjp_info,
    sweetin_info,
    sweetinpro_info,
};

void vendor_load_properties() {
    set_dalvik_heap();
    search_variant(variants);
}
