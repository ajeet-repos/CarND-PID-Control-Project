# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program
---

Final result:
![Final Result](http://i.imgur.com//NrPJjkr.gify)

## Reflection:
* Describe the effect each of the P, I, D components had in your implementation.
  * **P:** It has the most direct effect on the cars behaviour. Higher the value, higher is the effort made by the car to stay at center of the track. This resulted in car steering hard left or right, depending on how far it is from center.
  * **I:** As this is used to counteract any bias in CTE, it can have an effect on the steering angle. In this project it hepled the car in cornering better.
  * **D:** It helped balance the effect produced by the value of P and keept the car stable by helping the car steer to the center of track smoothly.
* Describe how the final hyperparameters were chosen.
  * Final values for P,I and D were choosen manually. I tried by first setting only the P parameter and observed how it affected the car. I tried with 0.01, 0.1, 0.2, 0.4, 0.8 and 1. Out of these values I found the values 0.1 and 0.2 were giving much better result than the rest.
  * After having some idea about the value for P, I started tuning for D. Here I observed that lower values were having less effects, so, I kept increasing the value by 50 or 100 and observed how smoother car steered to the center. With this I came to a conclusion that its value should be between 1000-2000.
  * Experimenting with these values for P and D were still not enough to keep the car to the track. So, keeping the value of P and D fixed I started reducing the throttle so that the car can have more time to react and center itself. This reduction had immediate effect of the car's parformance on track.
  * At this point, I had almost set on the values for **P - 0.1, D - 2000 and throttle - 15**. I only have to reduce the bias now so that car make good turns. I stared to tune **I** with 0.1 and slowly reached the final value of 0.000001.
  * final values
    * **P** : 0.15
    * **I** : 0.000001
    * **D** : 2000.0
    * **throttle** : 0.15

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./
