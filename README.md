# nordic_sdk_ci

## Objective
Create a GitHub CI pipeline using the Nordic SDK.

## Approach
The blinky example within the nRF5 SDK was chosen to serve as the source to be built within the CI pipeline. This source is to be built with Segger Embedded Studio (the Nordic-recommended IDE), run through a clang-format formatter, and have static analysis run by Cppcheck. These will serve as the three stages of the CI pipeline, occurring upon a push to the repo. 

In the future, a unit test stage could be added following the build using the Cpputest framework. In addition, the output files could be deployed to a device for use in integration tests. 

## Summary of Pipeline

### Build Firmware
The firmware is built within a docker container based on Ubuntu 18.04 and configured with SES v7.10a. The image's dockerfile is in the root of the repo. The dockerfile is run with the repo mounted, and SES is run on the blinky example. Following a successful build, the new .hex output file is exported as an artifact. 

### Formatting Check
The pertinent source files are checked for compliance to the clang-format rules dictated in the .clang-format file in the repo's root directory. These rules are based on the default LLVM style. The check is accomplished using a workflow by jidicula from the Github Actions Marketplace. 

### Static Analysis
Cppcheck C/C++ static analysis is run on the repo's source files. The analysis uses a workflow by deep5050 from Github Actions Marketplace. Currently, the Cppcheck results report are pushed to the repo upon completion. This may not be the best thing to do with the report, and this is a likely area of improvement for this CI approach. 

