      program functest
      implicit none
      
!     Make super duper double precision
      integer, parameter :: dp = kind(1.0d0)

!     don't forget to declare the function
      complex, external :: mult_fun

!     local variables
      complex(dp) :: a, b, c
      complex(dp), dimension (2,2) :: x, y, z
      real(dp), dimension (5) :: r

!     a = ((2.0,3.0), (5,6))
!     b = ((3.0, 4.0), (7,7))
      a = cmplx(2,3)
      b = cmplx(4,5)
      c = mult_fun(a, b)
      print *, 'Function result: ', c

      call mult_sub(a, b, c)
      print *, 'Subroutine result: ', c

      data x/(2, 3), (1, 4), (4,5), (7,8)/
      
      y = x+3
      print *, 'x: ', x
      print *, 'y: ', y

      print *, 'Now testing the array multiplication:'

      r = (/ 1, 2,3,5,5 /)
!     call mult_array(x, y, z)

!     print *, 'z: ', z
      
      end program functest



      
!     -------------------------------------------     
!     A FUNCTION 
      complex function mult_fun(x, y)
      implicit none
      integer, parameter :: dp = kind(1.0d0)
      complex(dp) :: x, y

!     value of the function must use the function name
      mult_fun = x * y

      end function mult_fun


c$$$  function f(n) result(r)
c$$$  integer, intent(in) :: n
c$$$  real(dp) :: r(n)
c$$$  integer :: i
c$$$  do i = 1, n
c$$$  r(i) = 1.0_dp / i**2
c$$$  enddo
c$$$  end function
      
!     -------------------------------------------
!     SUBROUTINES

      subroutine mult_sub(x, y, z)
      implicit none
      integer, parameter :: dp = kind(1.0d0)
      complex(dp), intent(in) :: x, y
      complex(dp), intent(out) :: z
      
      z = x*y
      
      end subroutine mult_sub

      subroutine mult_array(x, y, z)
      implicit none
      integer, parameter :: dp = kind(1.0d0)
      complex(dp), intent (in) :: x(:, :), y(:, :)
      complex(dp), intent (out) :: z(:, :)
      z = x+y 
      end subroutine mult_array


