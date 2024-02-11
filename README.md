# MudRock
MudRock is a cutting-edge C++ project designed for geoscientific analysis and visualization. This project showcases the power of combining custom libraries with external scientific computing libraries, all integrated within a Qt GUI framework. It leverages the capabilities of Eigen, Armadillo, and Boost to perform complex mathematical and statistical operations, making it an ideal tool for researchers, engineers, and developers working in the fields of geology, geophysics, and environmental science.

## Features

- **Custom Libraries**: Development of specialized libraries tailored for geoscientific data processing and analysis.
- **External Libraries Integration**: Incorporates Eigen, Armadillo, and Boost for advanced matrix operations, linear algebra, and more.
- **Qt GUI Framework**: User-friendly graphical interface for data visualization and interaction, built using the powerful Qt framework.
- **Comprehensive Testing**: Utilizes CTest for robust testing of library functions and GUI components, ensuring reliability and accuracy.

## Getting Started

Clone the repository using:

```
git clone https://github.com/scrooijmans/MudRock.git
```

### Prerequisites

- CMake (version 3.14 or newer)
- Qt (version 5 or 6)
- Eigen (version 3.4.0 or newer)
- Armadillo (version 10.1.0 or newer)
- Boost (version 1.71.0 or newer)

### Building the Project

Navigate to the project directory and create a build directory:

```
cd MudRock
mkdir build && cd build
```

Configure the project with CMake:

```
cmake ..
```

Build the project:

```
cmake --build .
```

### Running Tests

To run tests, use the following command in the build directory:

```
ctest
```

## License

MudRock is licensed under the MIT License. See the LICENSE file for more details.

## Acknowledgments

- Thanks to the developers of Eigen, Armadillo, and Boost for providing such powerful tools for scientific computing.
- Appreciation to the Qt community for their excellent GUI framework.

