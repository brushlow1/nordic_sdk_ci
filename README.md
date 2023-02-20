# nordic_sdk_ci

## Objective
Create a GitHub CI pipeline using the Nordic SDK.

## Approach
The blinky example within the nRF5 SDK was chosen to serve as the source to be built within the CI pipeline. This source is to be run through a clang-format formatter, have static analysis run by Cppcheck, and built with Segger Embedded Studio (the Nordic-recommended IDE) within a Docker container. These will serve as the three stages of the CI pipeline, occurring upon a push to the repo. 

In the future, a unit test stage could be added following the build using the Cpputest framework. 

