/* Copyright 2023 VMware, Inc.
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <yaml.h>

typedef enum ConfType {
        CONF_TYPE_MATCH,
        CONF_TYPE_NETWORK,
        CONF_TYPE_DHCP4,
        CONF_TYPE_DHCP6,
        CONF_TYPE_RA,
        CONF_TYPE_ADDRESS,
        CONF_TYPE_DNS,
        CONF_TYPE_ROUTE,
        CONF_TYPE_ROUTING_POLICY_RULE,
        CONF_TYPE_DHCP4_SERVER,
        CONF_TYPE_SRIOV,
        CONF_TYPE_NETDEV,
        CONF_TYPE_LINK,
        CONF_TYPE_NETDEV_VLAN,
        CONF_TYPE_NETDEV_MACVLAN,
        CONF_TYPE_NETDEV_BRIDGE,
        CONF_TYPE_NETDEV_BOND,
        CONF_TYPE_NETDEV_TUNNEL,
        CONF_TYPE_NETDEV_VRF,
        CONF_TYPE_NETDEV_VXLAN,
        CONF_TYPE_NETDEV_WIREGUARD,
        CONF_TYPE_WIFI,
        _CONF_TYPE_MAX,
        _CONF_TYPE_INVALID = -EINVAL,
} ConfType;

typedef struct ParserTable {
        const char *key;
        ConfType type;
        int (*parser) (const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
        const size_t offset;
} ParserTable;

const char *conf_type_to_name(int id);
int conf_type_to_mode(const char *name);

int parse_yaml_bool(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_uint64(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_uint32(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_uint16(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_uint32_or_max(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_mac_address(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_string(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_scalar_or_sequence(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_sequence(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);

int parse_yaml_keep_configuration(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_route(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_route_type(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_route_scope(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);

int parse_yaml_auth_key_management_type(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);

int parse_yaml_dhcp_client_identifier(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_dhcp_type(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_addresses(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_address(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_nameserver_addresses(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_domains(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_link_local_type(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_ipv6_address_generation_mode(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_ipv6_privacy_extensions(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_rf_online(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_activation_policy(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);

int parse_yaml_bond_mode(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_vxlan_notifications(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_vxlan_csum(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_vxlan_extensions(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_vxlan_port_range(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);

int parse_yaml_bond_lacp_rate(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_bond_arp_validate(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_bond_fail_over_mac(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_bond_ad_select(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_bond_primary_reselect(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_bond_xmit_hash_policy(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);

int parse_yaml_wireguard_key_or_path(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_sequence_wireguard_peer_shared_key_or_path(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);

int parse_yaml_macvlan_mode(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_infiniband_mode(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_dhcp6_without_ra(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);

int parse_yaml_bridge_path_cost(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_bridge_port_priority(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);

int parse_yaml_sriov_vlan_protocol(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
int parse_yaml_sriov_link_state(const char *key, const char *value, void *data, void *userdata, yaml_document_t *doc, yaml_node_t *node);
