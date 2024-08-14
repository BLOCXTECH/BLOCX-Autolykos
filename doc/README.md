BLOCX_TESTNET Core
==========

This is the official reference wallet for BLOCX_TESTNET digital currency and comprises the backbone of the BLOCX_TESTNET peer-to-peer network. You can [download BLOCX_TESTNET Core](https://www.blocx_testnet.org/downloads/) or [build it yourself](#building) using the guides below.

Running
---------------------
The following are some helpful notes on how to run BLOCX_TESTNET Core on your native platform.

### Unix

Unpack the files into a directory and run:

- `bin/blocx_testnet-qt` (GUI) or
- `bin/blocx_testnetd` (headless)

### Windows

Unpack the files into a directory, and then run blocx_testnet-qt.exe.

### macOS

Drag BLOCX_TESTNET Core to your applications folder, and then run BLOCX_TESTNET Core.

### Need Help?

* See the [BLOCX_TESTNET documentation](https://docs.blocx_testnet.org)
for help and more information.
* Ask for help on [BLOCX_TESTNET Discord](http://stayblocx_testnety.com)
* Ask for help on the [BLOCX_TESTNET Forum](https://blocx_testnet.org/forum)

Building
---------------------
The following are developer notes on how to build BLOCX_TESTNET Core on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [Dependencies](dependencies.md)
- [macOS Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Windows Build Notes](build-windows.md)
- [OpenBSD Build Notes](build-openbsd.md)
- [NetBSD Build Notes](build-netbsd.md)
- [Gitian Building Guide](gitian-building.md)

Development
---------------------
The BLOCX_TESTNET Core repo's [root README](/README.md) contains relevant information on the development process and automated testing.

- [Developer Notes](developer-notes.md)
- [Productivity Notes](productivity.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
- Source Code Documentation ***TODO***
- [Translation Process](translation_process.md)
- [Translation Strings Policy](translation_strings_policy.md)
- [Travis CI](travis-ci.md)
- [JSON-RPC Interface](JSON-RPC-interface.md)
- [Unauthenticated REST Interface](REST-interface.md)
- [Shared Libraries](shared-libraries.md)
- [BIPS](bips.md)
- [Dnsseed Policy](dnsseed-policy.md)
- [Benchmarking](benchmarking.md)

### Resources
* See the [BLOCX_TESTNET Developer Documentation](https://blocx_testnetcore.readme.io/)
  for technical specifications and implementation details.
* Discuss on the [BLOCX_TESTNET Forum](https://blocx_testnet.org/forum), in the Development & Technical Discussion board.
* Discuss on [BLOCX_TESTNET Discord](http://stayblocx_testnety.com)
* Discuss on [BLOCX_TESTNET Developers Discord](http://chat.blocx_testnetdevs.org/)

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [blocx_testnet.conf Configuration File](blocx_testnet-conf.md)
- [Files](files.md)
- [Fuzz-testing](fuzzing.md)
- [Reduce Memory](reduce-memory.md)
- [Reduce Traffic](reduce-traffic.md)
- [Tor Support](tor.md)
- [Init Scripts (systemd/upstart/openrc)](init.md)
- [ZMQ](zmq.md)
- [PSBT support](psbt.md)

License
---------------------
Distributed under the [MIT software license](/COPYING).
