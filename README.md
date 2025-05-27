# Fractol

A graphical program to visualize the Mandelbrot and Julia sets.

## Description

This project displays the Mandelbrot and Julia sets using a Minilibx. It was created as a learning exercise to explore and manipulate a graphics library.

## Installation

1.  Clone the repository:

    ```bash
    git clone git@github.com:Husam-Ahmad/fractol.git
    ```

## Usage

1.  Compile the code:

    ```bash
    make
    ```

2.  Run the program:

    ```bash
    ./fractol <set_name> [optional parameters]
    ```

    Where `<set_name>` can be one of the following:

    *   `mandelbrot`: Displays the Mandelbrot set.
    *   `julia`: Displays the Julia set with -0.162 and 1.04 as default parameters.
    *   `julia <number1> <number2>`: Displays the Julia set with custom parameters.  
