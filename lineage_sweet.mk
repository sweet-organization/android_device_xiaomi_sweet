#
# Copyright (C) 2021-2025 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
TARGET_SUPPORTS_OMX_SERVICE := false
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)

# Inherit from sweet device.
$(call inherit-product, device/xiaomi/sweet/device.mk)

# Inherit some common LineageOS / Evolution-X stuff.
$(call inherit-product, vendor/lineage/config/common_full_phone.mk)

# MiuiCamera
TARGET_USES_LEICA_HOLY50 := true

# Bootanimation
TARGET_INCLUDE_BOOT_ANIMATIONS := true
TARGET_SCREEN_WIDTH := 1080
TARGET_SCREEN_HEIGHT := 2400

# TARGETS
TARGET_INCLUDE_VIPERFX := false
TARGET_DISABLE_LINEAGE_SDK := false
TARGET_DISABLE_EPPE := false
TARGET_BUILD_APERTURE_CAMERA := true
TARGET_EXCLUDES_AUDIOFX := true
TARGET_BUILD_DEVICE_AS_WEBCAM := true

# Face Unlock
TARGET_SUPPORTS_64_BIT_APPS := true

# Enable blur
TARGET_ENABLE_BLUR := true

# BCR
TARGET_INCLUDE_BCR := true

# Other ROM feature flags
BYPASS_CHARGE_SUPPORTED := false
PERF_ANIM_OVERRIDE := false
TORCH_STR_SUPPORTED := false

# Udfps
TARGET_HAS_UDFPS := false

# Device identifier
PRODUCT_NAME := lineage_sweet
PRODUCT_DEVICE := sweet
PRODUCT_BRAND := Xiaomi
PRODUCT_MODEL := Redmi Note 10 Pro
PRODUCT_MANUFACTURER := Xiaomi

# GMS
ifeq ($(WITH_GMS),true)
TARGET_USES_MINI_GAPPS := false
TARGET_USES_PICO_GAPPS := false
TARGET_SUPPORTS_QUICK_TAP := true
TARGET_INCLUDE_LIVE_WALLPAPERS := true
TARGET_INCLUDE_STOCK_ARCORE := true
TARGET_SUPPORTS_GOOGLE_RECORDER := true
endif
PRODUCT_GMS_CLIENTID_BASE := android-xiaomi

# Properties
PRODUCT_BUILD_PROP_OVERRIDES += \
    BuildDesc="sweet_global-user 13 TKQ1.221013.002 V14.0.9.0.TKFMIXM release-keys" \
    BuildFingerprint=Redmi/sweet_global/sweet:13/TKQ1.221013.002/V14.0.9.0.TKFMIXM:user/release-keys
