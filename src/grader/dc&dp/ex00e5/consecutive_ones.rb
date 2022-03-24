def gen(sol, l, c, mc, n, k)
  if (c == k)
    mc = true
  end
  if (l == n)
    if (mc)
      puts sol
    end
    return
  end
  gen(sol + "0", l + 1, 0, mc, n, k)
  gen(sol + "1", l + 1, c + 1, mc, n, k)
end

n, k = gets.split.map { |x| x.to_i }
gen("", 0, 0, false, n, k)
