/* SPDX-License-Identifier: Apache-2.0
 * Copyright © 2020 VMware, Inc.
 */

#pragma once

#include <linux/netfilter.h>
#include <linux/netfilter/nf_tables.h>
#include <libmnl/libmnl.h>
#include <libnftnl/table.h>

typedef enum NfProtoFamily {
        NF_PROTO_FAMILY_UNSPEC = NFPROTO_UNSPEC,
        NF_PROTO_FAMILY_INET   = NFPROTO_INET,
        NF_PROTO_FAMILY_IPV4   = NFPROTO_IPV4,
        NF_PROTO_FAMILY_ARP    = NFPROTO_ARP,
        NF_PROTO_FAMILY_NETDEV = NFPROTO_NETDEV,
        NF_PROTO_FAMILY_BRIDGE = NFPROTO_BRIDGE,
        NF_PROTO_FAMILY_IPV6   = NFPROTO_IPV6,
        NF_PROTO_FAMILY_DECNET = NFPROTO_DECNET,
        _NF_PROTO_FAMILY_MAX,
        _NF_PROTO_FAMILY_INVALID = -1
} NfProtoFamily;

const char *nft_family_to_name(int id);
int nft_family_name_to_type(char *name);

void nft_tables_unref(struct nftnl_table **t);

int new_nft_table(int family, const char *name, struct nftnl_table **ret);
int nft_add_table(int family, const char *name);
int nft_get_tables(int family, char ***ret);
