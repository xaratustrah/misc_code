      program mult
      IMPLICIT NONE
!     declare variables
      integer, parameter :: dp=kind(1.0d0)
      real(dp) :: a,b,c,d,e,f
      real(dp), allocatable, dimension(:,:) :: myArray
      complex(dp) :: g
      complex(dp), allocatable, dimension(:,:) :: cplxary
      
      a = 1.0
      b = 2.0
      d     = 1.0
      e = 3.0
!     Call subroutine and pass a,b,c
      call addsubber(a,b,c)
!     c now equals 3.0
!     Note I can reuse the same subroutine with different numbers
      call addsubber(d,e,f)
!     f now equals 4.0
      print *, SIN(f)

      allocate(myArray(3,4))
      myArray = 0.0_dp

      print *, maxval(myArray)
      deallocate(myArray)

!      g = 0.0_dp
      g = (2,3)

      allocate(cplxary(5,5))
      cplxary = 0.0_dp

      print *, g, cos(cplxary)

      deallocate(cplxary)

      
      END PROGRAM mult
!     After program has ended I can declare my subroutine.

      
      SUBROUTINE addsubber(x,y,z)
      IMPLICIT NONE
!     Local variable declarations
      integer, parameter :: dp=kind(1.0d0)
!     Declare Dummy variables
      real(dp), INTENT(IN)  :: x,y
      real(dp), INTENT(OUT) :: z
      z=x+y
      END SUBROUTINE
