      
		// Induction rule is very similar to edit distance, where we also consider from the end. And it is based on what character in the pattern we meet.
        1. if p.charAt(j) == s.charAt(i)  | p.charAt(j) == '.' // 当前对位元素相同，对比结果取决于前面###的对比结果
                M[i][j] = M[i - 1][j - 1]
		//    ######a
		//    ####a
        2. if p.charAt(j) == '*':
           1. if p.charAt(j - 1) != s.charAt(i) && p.charAt(j - 1) != '.' // b* is counted as empty，a还在，并且有被抵消 
                 //   #####a
                 //   ####b*
                 M[i][j] = M[i][j - 2]   
           2.if p.charAt(j - 1) == s.charAt(i) || p.charAt(j - 1) == '.' :
                //   ######a
                //   ####.*
            s
                //  #####a
                //  ###a*
                2.1 if  then M[i][j] = M[i][j - 2]  // 匹配0次， a还在，并且有被抵消 
                2.2 if counted as one, then M[i][j] = M[i - 1][j - 2]  // 匹配1次，'a'，和'.*'都被抵消了
                2.3 if counted as multiple, then M[i][j] = M[i - 1][j] // 只要###部分相同，整个表达式就相同。a还在，并且有被抵消 
                // 之所以没用M[i - 1][j - 2]，是因为
                //  aa
                //  a* 如果按照上面的公式，就是对比dp[1][0]，而dp[1][0]是flase