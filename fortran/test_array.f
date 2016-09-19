! explicit one dimension array passing test
      
      program test_array
      implicit none
      integer, parameter :: dp = kind(1.0d0)
      real(dp), dimension (:,:), allocatable :: r, s

      allocate(r(2,3))
      allocate(s(2,3))
      r = reshape([ 1, 2, 3, 4, 5, 6], [size(r, 2), size(r, 1)])

      call f2(shape(r), r, s)

      !print *, s

      print *, shape(r)
      end program test_array
      





      subroutine f2(m, n, rin, rout)
      implicit none
      integer, parameter :: dp = kind(1.0d0)
      integer, intent(in) :: m, n
      real(dp), intent(in) :: rin(m,n)
      real(dp), intent(out) :: rout(m,n)
      integer :: i, j

      do i = 1, m
         do j = 1, n
            rout(i, j) = rin(i, j) * 2
         enddo
      enddo

      end subroutine

