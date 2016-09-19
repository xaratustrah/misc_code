      program writetest
      implicit none
      integer :: i
      integer :: ios            ! this is a standard name for error checking
      OPEN(UNIT=22, FILE="myFile.dat", iostat=ios)
      IF(ios.ne.0) STOP "Error in opening file"
      do i = 1,10
         WRITE(22,*) real(i), real(i)**2
      end do
      CLOSE(UNIT=22,iostat=ios)
      IF(ios.ne.0) STOP "Error in closing file"
      end program
      
