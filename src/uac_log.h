// Copyright 2019 Fuzhou Rockchip Electronics Co., Ltd. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _RK_UAC_LOGGER_H_
#define _RK_UAC_LOGGER_H_

#ifdef ENABLE_MINILOGGER
#include "minilogger/log.h"
#else
#define minilog_warn(...)
#define minilog_error(...)
#define minilog_info(...)
#define minilog_debug(...)
#define __minilog_log_init(...)
#endif

extern int enable_minilog;
extern int uac_app_log_level;

#define LOG_LEVEL_ERROR 0
#define LOG_LEVEL_WARN  1
#define LOG_LEVEL_INFO  2
#define LOG_LEVEL_DEBUG 3

#ifndef LOG_TAG
#define LOG_TAG "uac_app"
#endif // LOG_TAG

#define ALOGI(format, ...)                                                  \
  do {                                                                         \
    if (uac_app_log_level < LOG_LEVEL_INFO)                                    \
      break;                                                                   \
    if (enable_minilog)                                                        \
      minilog_info("[%s][%s]:" format, LOG_TAG, __FUNCTION__, ##__VA_ARGS__);  \
    else                                                                       \
      fprintf(stderr, "[%s][%s]:" format, LOG_TAG, __FUNCTION__,               \
              ##__VA_ARGS__);                                                  \
  } while (0)

#define ALOGW(format, ...)                                                  \
  do {                                                                         \
    if (uac_app_log_level < LOG_LEVEL_WARN)                                \
      break;                                                                   \
    if (enable_minilog)                                                        \
      minilog_warn("[%s][%s]:" format, LOG_TAG, __FUNCTION__, ##__VA_ARGS__);  \
    else                                                                       \
      fprintf(stderr, "[%s][%s]:" format, LOG_TAG, __FUNCTION__,               \
              ##__VA_ARGS__);                                                  \
  } while (0)

#define ALOGE(format, ...)                                                 \
  do {                                                                         \
    if (uac_app_log_level < LOG_LEVEL_ERROR)                               \
      break;                                                                   \
    if (enable_minilog)                                                        \
      minilog_error("[%s][%s]:" format, LOG_TAG, __FUNCTION__, ##__VA_ARGS__); \
    else                                                                       \
      fprintf(stderr, "[%s][%s]:" format, LOG_TAG, __FUNCTION__,               \
              ##__VA_ARGS__);                                                  \
  } while (0)

#define ALOGD(format, ...)                                                 \
  do {                                                                         \
    if (uac_app_log_level < LOG_LEVEL_DEBUG)                               \
      break;                                                                   \
    if (enable_minilog)                                                        \
      minilog_debug("[%s][%s]:" format, LOG_TAG, __FUNCTION__, ##__VA_ARGS__); \
    else                                                                       \
      fprintf(stderr, "[%s][%s]:" format, LOG_TAG, __FUNCTION__,               \
              ##__VA_ARGS__);                                                  \
  } while (0)

#endif  //  _RK_UAC_LOGGER_H_
