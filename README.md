# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Project Description

This project illustrates the implementation of a PID controller to control both car steering and throttle. PID controller was manually tuned to achieve maximum speed while following target line/curve and remaining within boundaries of the road. As a result, current parameters of PID controller demonstrate the sportier behavior.

## Tuning PID parameters
**Steering PID controller** - parameters were tunned manually. Proportional gain parameters were set a relatively high value - 1.0 to enforce fast reaction to the cross-track error (CTE). Differentiable gain was implemented without normalization for the value of ∂t. Therefore, the Differentiable gain is highly sensitive to the frequency of CTE. As the simulator runs on a relatively high measurement frequency, the differentiable gain was set high enough to compensate isolation introduced by an aggressive proportional gain parameter.

In addition, steering PID value was normalized to the speed function, where the speed function defined as the square root of 1 plus double the speed measurement: f(speed) = sqrt( 1 + 2*speed ). The idea of speed normalization introduced to negate the speed impact on the effect of PID gain parameters. The constant +1 removes the error of division by 0, and the speed caller was chosen manually assuming constant 0.7 throttle value.

**Throttle PID controller** - parameters were tuned manually. The measure of error was set to square of CTE to reflect positive nature of throttle reduction and exponential impact of the speed on CTE behavior.

The proportional gain was set to the relatively high value of 1.0 to reflect the need to quickly decelerate when CTE starts to deviate from 0. In addition, the differentiable gain was also set to a high value of 10.0, to reflect a high frequency of measurement and induce the fast gain in throttle when the CTE starts to decline.

The simulator doesn't show symptoms of a systematic bias. Therefore, the integral gain was set to 0 for both steering and throttle PID controllers.



## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
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
