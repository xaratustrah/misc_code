program signal
  implicit none

  real :: f0,fs,t1,ts,t0,sig(2**20),pi=acos(-1.)
  integer :: t

  f0 = 4.0    ! starting frequency in Hz
  fs = 100.0  ! sampling frequency in Hz
  t0 = 0.0    ! starting time in s
  t1 = 0.5;   ! end time in s
  ts = 1/fs;  ! time difference between samples

  sig = (/(sin(2*pi*f0*t),t=1,2**20)/)
!  print *, sig
end program signal





! ----------------------------------------------------------
! ----------------------------------------------------------
! ----------------------------------------------------------
! code eimer
!do t=1,1024
!	sig = sin(2*3.14*f0*t);
!end do
! real, dimension (3) :: a=(/(j**2+j,j=1,3)/)
