program test implicit none integer, parameter :: dp = kind(1.0d0)
  real(dp) :: x real:: y

  y = 4.3
  x = 4.3_dp

  print *, 'x: ', x
  print *, 'y: ', y
  
end program test
