PROGRAM palindrome
  implicit none
  integer :: i
  do while(.true.)
    read *, i
    if(i == 0) then
      exit
    end if
    if(is_palindrome(i)) then
      print '(a)', "yes"
    else
      print '(a)', "no"
    end if
  end do
    ! print *, is_palindrome(i)

  Contains
  function is_palindrome(i)
    integer :: n,tmp,i
    logical :: is_palindrome

    tmp = i
    n = 0
    do while(tmp /= 0)
      n = n*10
      n = n + mod(tmp, 10)
      tmp = tmp/10
    end do
    if(i==n) then
      is_palindrome = .true.
    else
      is_palindrome = .false.
    end if
  end function is_palindrome

end PROGRAM palindrome
