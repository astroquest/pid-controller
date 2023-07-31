# pid-controller
PID controller written in C++, derived from a Tustin discretization of the PID Laplace transform.
The PID Laplace transform is given by
$$\frac{U(s)}{E(s)} = k_p\left(1 + k_i\frac{1}{s} + k_d\frac{s}{( k_t s + 1)} \right)$$

Where $k_p$, $k_i$, and $k_d$ are the proportional, integral, and derivative gains, respectively. $k_t$ is the time constant of the first-order low-pass filter on the derivative term and is inversely proportional to the cut-off frequency of the filter. $U$ is the control action and $E$ is the error between the setpoint/reference and the process variable/system output (SP - PV).

The Laplace form is intuitive for frequency-domain tuning, but not implementable in a digital system. The Tustin discretization approximates the Laplace transform with a discrete-time z-transform, according to the definition
$$s = \frac{2}{T}\frac{1-z^{-1}}{1+z^{-1}}$$

With $T$ being the sampling time. By inserting the expression into the Laplace transform, z-transforms can be derived for both the integral and derivative actions. The integral action $z$-transform is given by
$$(1-z^{-1})U_I(z) = k_i\frac{t}{2}\left(1 + z^{-1}\right) E(z)$$

and the derivative action is
$$\left(1+\frac{T-2k_t}{T+2k_t}z^{-1}\right)U_D(z)=\frac{2k_d}{2k_t+T}(1-z^{-1}) E(z)$$

In discrete time, the $z$ operator can be interpreted as a time index, with $z^0\rightarrow [k]$ and $z^{-1}\rightarrow [k-1]$. With this insight, the $z$-transform of the integral is converted to the difference equation
$$u_I[k] = u_I[k-1] + k_i\frac{T}{2}(e[k] + e[k-1])$$

and the derivative action is
$$u_D[k] = \frac{2k_t - T}{2k_t + T}u_d[k-1] + \frac{2k_d}{2k_t+T}\left(e[k] - e[k-1] \right)$$

Setpoints are often constant or only slowly varying, so the error in the derivative action is usually replaced by minus the process variable (since $e = SP - PV \rightarrow e[k] - e[k-1] \approx -PV[k] + PV[k-1]$), leading to
$$u_D[k] = \frac{2k_t - T}{2k_t + T}u_D[k-1] - \frac{2k_d}{2k_t+T}\left(PV[k] - PV[k-1] \right)$$

This can also help with avoiding large control action spikes when a large setpoint change is applied.
