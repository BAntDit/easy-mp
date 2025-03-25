
# metrix

meta-programming tricks library

## Build dependencies
[CONAN](https://conan.io/) - The open source, decentralized and multi-platform package
manager to create and share all your native binaries.

## Dependencies

1. [GTest](https://github.com/google/googletest) - Google Testing and Mocking Framework

## Project setup 

1. Install conan: [Installation instruction](https://docs.conan.io/2/installation.html)

2. Clone project: `git clone git@github.com:BAntDit/easy-mp.git` 

3. Install dependencies: `conan install . -s build_type=<Configuration> --build=missing --output-folder=<Out Folder>`

4. Deploy to local conan cache: `conan create . -s build_type=<Configuration>`
