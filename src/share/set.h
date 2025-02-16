/* Copyright 2023 VMware, Inc.
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include <glib.h>

typedef struct Set {
        GHashTable *hash;
} Set;

int set_new(Set **ret, GHashFunc hash_func, GEqualFunc compare_func);
void set_free(Set *s);

DEFINE_CLEANUP(Set *, set_free);

#define set_size(s)  g_hash_table_size(s->hash)

bool set_add(Set *s, void *k);
bool set_contains(Set *s, void *k);
void set_foreach(Set *s, GHFunc func, gpointer user_data);
