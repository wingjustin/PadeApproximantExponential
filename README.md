# PadeApproximantExponential

<h3>帕德近似</h3>

<p>
帕德近似為有理函數逼近
<br><br>有理函數p(x)愈接近0效果愈好
<br><br>這時可以考慮約簡x
<br><br>exp(x) 拆成 exp(k*ln2) * exp(r), where -0.5*ln(2) <= r <= 0.5*ln(2)
<br><br>e^x = 2^k * (1 + f)                 , /* k is integer */IEEE745
<br>ln(e^x) = ln(2^k * (1+f))
<br>x = k * ln(2) + ln(1+f)
<br>x = k * ln(2) + ln(2) * (ln(1+f)/ ln(2))
<br>x = k * ln(2) + ln(2) * (log(1+f))
<br>x = k * ln(2) + r
<br>e^x = e^(k * ln(2)) *  e^r
<br>接下來對r用逼近函數估算e^r,
<br>再把e^r跟k合併即可, k為e^x的階碼

<div>References : </div>
<ul>
<li>FdLibM C math library .\fdlibm-5.2\e_exp.c : https://gnuwin32.sourceforge.net/packages/fdlibm.htm</li>
<li>https://zhuanlan.zhihu.com/p/541466411</li>
<li>https://blog.csdn.net/m0_66201040/article/details/125866121</li>
</ul>
