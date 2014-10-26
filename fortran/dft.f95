program dft
  implicit none
  !real, parameter::pi = 3.141592653589793
  integer, parameter::count = 2 * 3
  !real::phi
  !integer::n, k
  !complex::in(count), out(count)
  real::f0, fs, t1, ts, t0
  integer::t

  f0 = 4.0 ! starting frequency in Hz
  fs = 100.0 ! sampling frequency in Hz
  t0 = 0.0 ! starting time in s
  t1 = 0.5;
  !end time in s
  ts = 1 / fs;
  !time difference between samples

  do t = 1, count
     in(t) = ( cos(2 * pi * f0 * t) , sin(2 * pi * f0 * t) )
  end do
  do k = 1, count
     do n = 1, count
        phi = 2 * pi * n * k / 4
        write(*, *) real(in(n)) * cos(phi) / count, aimag(in(n)) * sin(phi) / count
     end do
  end do
end program dft
