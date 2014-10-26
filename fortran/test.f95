program test
  implicit none
  integer::t
  complex::in(4)
  do t = 1, 5
     in(t) = ( 2.0, 3.0 ) ! works only for constants
     in(t) = cmplx(t*2 , t**4) ! works also with variables
  end do
  write (*,*) in
end program test
