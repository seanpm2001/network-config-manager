/* Copyright 2023 VMware, Inc.
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include <glib.h>

#define log_debug   g_debug
#define log_error   g_error
#define log_warning g_warning
#define log_notice  g_notice
#define log_info    g_info

static inline int log_warning_errno(int r, char *message) {
       log_warning("%s: %s", message, strerror(-r));
       return r;
}

static inline int log_oom(void) {
        log_warning("Out of memory");
        return -ENOMEM;
}
