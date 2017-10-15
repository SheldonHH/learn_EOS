# Phase 1 Features Included in this Release

Per the [EOS.IO Roadmap](https://github.com/EOSIO/Documentation/blob/master/Roadmap.md), this release represents Phase 1, the Minimal Viable Testing Environment.

## Programs

- a standalone node **eosd** that produces blocks and adds them to the blockchain，单节点测试网络
- a client **eosc** that provides a command line interface， 命令行界面
- **eos-walletd** provides a client wallet server，  EOS钱包
- a utility **launcher** that creates a local testnet 、 测试器用于创建当地网络



## Scripts

- **build.sh** to install dependencies and build eos
- **eoscpp** for smart contract developers to build contracts

## Example Contracts

- native contracts,
  - native currency
  - staking
  - producer voting
  - code updating
  - permission updating
- example contracts
  - dice
  - exchange
  - simpledb
  - social

## Documentation

- virtual machine API
  - deferred / inline messaging
  - user-local storage for contracts
  - 3 built in database types
- basic developer documentation
  - installation and setup
  - build and deployment
  - tutorial for trying out blockchain commands
  - Doxygen based API reference