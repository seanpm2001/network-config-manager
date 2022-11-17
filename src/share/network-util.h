/* Copyright 2022 VMware, Inc.
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <arpa/inet.h>
#include <assert.h>
#include <glib.h>
#include <net/if.h>
#include <linux/if.h>
#include <net/ethernet.h>
#include <netinet/ether.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "macros.h"

#define ETHER_ADDR_FORMAT_STR "%02X%02X%02X%02X%02X%02X"
#define ETHER_ADDR_TO_STRING_MAX (3*6)

#define parse_ether_address(mac) ether_aton(mac)


typedef enum AddressFamily {
        ADDRESS_FAMILY_NO,
        ADDRESS_FAMILY_IPV4,
        ADDRESS_FAMILY_IPV6,
        ADDRESS_FAMILY_YES,
        _ADDRESS_FAMILY_MAX,
        _ADDRESS_FAMILY_INVALID = -EINVAL,
} AddressFamily;

typedef struct IPAddress {
        struct in_addr in;
        struct in6_addr in6;

        int family;
        int prefix_len;
} IPAddress;

typedef struct IfNameIndex {
        int ifindex;

        char ifname[IFNAMSIZ];
} IfNameIndex;

int ip_to_string(int family, const struct IPAddress *u, char **ret);
int ip_to_string_prefix(int family, const struct IPAddress *u, char **ret);

int parse_ipv4(const char *s, IPAddress **ret);
int parse_ipv6(const char *s, IPAddress **ret);
int parse_ip(const char *s, IPAddress **ret);
int parse_ip_port(const char *s, IPAddress **ret, uint16_t *port);

int parse_ip_from_string(const char *s, IPAddress **ret);
int ipv4_netmask_to_prefixlen(IPAddress *addr);

bool ip4_addr_is_null(const IPAddress *a);
int ip_is_null(const IPAddress *a);

int parse_ifname_or_index(const char *s, IfNameIndex **ret);
char *ether_addr_to_string(const struct ether_addr *addr, char *s);
bool ether_addr_is_not_null(const struct ether_addr *addr);
int parse_mtu(char *mtu, uint32_t *ret);

int parse_group(char *mtu, uint32_t *ret);
int parse_link_rf_online(const char *c);
int parse_link_act_policy(const char *c);

bool valid_hostname(const char *host);
bool valid_ifname(const char *s);

const char *address_family_type_to_name(int id);
int address_family_name_to_type(const char *name);
