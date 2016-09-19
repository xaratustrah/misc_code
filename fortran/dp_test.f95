program test
  implicit none
  integer, parameter :: dp = kind(1.0d0)
  real(dp) :: x, y
  integer :: a, b

  a = 3
  b = 5
  x = 4.3
  y = 4.3_dp

  print *, 'a: ', a
  print *, 'b: ', b
  print *, 'x: ', x
  print *, 'y: ', y
  print *, 'a*b: ', a*b
  print *, 'a*x: ', a*x
  print *, 'x*a: ', x*a
  print *, 'a*y: ', a*y
  print *, 'x*y: ', x*y
  
end program test
