# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/), and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added
- Docker support for local and containerized builds
- Docker Compose configuration to run the optimizer demo
- Build output ignore rules for Docker and Git
- README updates with local and container build instructions
- Adam optimizer math explanation in the documentation

### Changed
- Updated the project build instructions to use CMake in a supported version range

### Fixed
- Resolved the CMake version mismatch preventing the project from configuring on the installed toolchain

## [1.0.0] - 2026-09-18

### Added
- Initial Adam optimizer implementation in C++
- AMSGrad support
- Weight decay support
- Simple training example in `main.cpp`
