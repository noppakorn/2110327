def gen(n, sol, len, sum, k)
  if (len < n)
    if (sum <= k)
      sol += "0"
      gen(n, sol, len + 1, sum, k)
      sol[len] = "1"
      gen(n, sol, len + 1, sum + 1, k)
    end
    return
  else
    if (sum == k)
      puts sol
    end
    return
  end
end

k, n = gets.split.map { |x| x.to_i }
gen(n, "", 0, 0, k)
