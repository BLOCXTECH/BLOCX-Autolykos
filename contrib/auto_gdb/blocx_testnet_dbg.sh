#!/usr/bin/env bash
# Copyright (c) 2018-2020 The Dash Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.
# use testnet settings,  if you need mainnet,  use ~/.blocx_testnetcore/blocx_testnetd.pid file instead
export LC_ALL=C

blocx_testnet_pid=$(<~/.blocx_testnetcore/testnet3/blocx_testnetd.pid)
sudo gdb -batch -ex "source debug.gdb" blocx_testnetd ${blocx_testnet_pid}
