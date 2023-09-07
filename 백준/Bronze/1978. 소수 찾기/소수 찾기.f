PROGRAM prime
  implicit none
  integer :: input, arr(101), cnt, n
  read *, input
  read *, (arr(n), n=1, input)
  cnt = 0
  do n = 1, input
    if(is_prime2(arr(n))) then
      cnt = cnt + 1
    end if
  end do
  print '(I0)', cnt

  Contains
  function is_prime2(input)
    integer :: input, i, j
    logical :: is_prime2

    if(input == 1) then
      is_prime2 = .false.
    else if(input == 2 .Or. input == 3) then
      is_prime2 = .true.
    else
      do i=2, int(sqrt(real(input)))
        if(mod(input,i)==0) then
          is_prime2 = .false.
          return
        end if
      end do
      is_prime2 = .true.
    end if
  end function is_prime2
end PROGRAM prime
