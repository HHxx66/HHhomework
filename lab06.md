# 贝尔定律与现实

**戈登·贝尔**

戈登·贝尔（GordonBell），1934年8月19日出生于美国密苏里州的柯克斯维尔，微软湾区研究中心高级研究员。作为DEC的技术灵魂，贝尔构思、设计和主持开发的计算机PDP-4，PDP-5，PDP-6，PDP-8，PDP-10及PDP-11使计算机工业翻天覆地。如果要为DEC建造一座名人堂，那么戈登·贝尔的像就应该紧挨着奥尔森。在某种意义上，他才是DEC真正的电脑英雄。他是一位计算机天才，是DEC的技术灵魂。《数据信息》杂志称他为计算机业的弗兰克·赖特，后者是美国最伟大的建筑家。

![](https://gss0.bdstatic.com/-4o3dSag_xI4khGkpoWK1HF6hhy/baike/w%3D268%3Bg%3D0/sign=05b09ad96581800a6ee58e08890e54c7/09fa513d269759eee985039dbbfb43166c22df8b.jpg)

他在1972年的文章中指出，大约每过十年，半导体、存储、接口以及网络的发展就会推动一个新的、价格更为低廉的计算机“领域”的发展，同时也会推动新的行业和市场的发展。这往往会取代（至少部分取代）旧的产品。这也就是贝尔定律。

**贝尔定律**

贝尔定律的基本表述为：大约每隔十年，新的价格更低的计算机设备就会出现，这将会改变一切,推动新的行业和市场的发展。并且，这往往会取代（至少部分取代）旧的产品。

![](https://pic4.zhimg.com/80/v2-fc6fe5524ecd35768d898752cbcbfa6e_hd.jpg)

就当今来说，智能手机由于其方便，价格更低，已经取代了很多个人计算机。之前则是个人计算机取代了使用较为不方便的小型计算机。再之前则是小型计算机取代了使用更加不方便而且还特别耗费体积的大型计算机。这些情况也无不反映出贝尔定律，它表明：技术不间断地从平衡、不平衡到再平衡的演化，反复地将世界推向一个新常态。

![](https://pic2.zhimg.com/80/v2-630e09b82a7a8c7a107cb100cedb56bc_hd.jpg)

**典型例子**

当今火热地物联网已经推动了银行、汽车、国防、医疗保健以及安全行业的巨大发展。随着物联网的发展，嵌入式计算机提供的机会将变得更为明确，并且毫无疑问的是，这个新事物将会同之前的技术一样具有变革性，也就是说旧的产品也将会取代。

当今我们印象较深的应该就是iPhone了，iPhone每次更新换代都会引起一大波国人淘汰旧iPhone追求新款的iPhone，更有卖肾之说。这些现象也与贝尔定律相符。

[若想了解更多可前往贝尔定律的维基百科](https://en.wikipedia.org/wiki/Bell%27s_law_of_computer_classes)

Proof:

$\because$ Positional Notation $${(x)}_{2} = \sum_{i=1}^{k}d_{i}2^{i-1}$$  

$\because$ Two's complement 

$$N(x) = 2^{k} - x$$, where k is the number of bits for an integer

and, $$N'(x) = 2^{m} - x$$ where $$m > k$$

$\therefore$ $$N'(x) = 2^{m} - x = (2^{m} - 2^{k}) +  2^{k} - x = (2^{m}-1) - (2^{k}-1) + N(x)$$

$\because$ $$2^{m}-1 = (2-1)\sum_{i=1}^{m}2^{i-1}$$, that is m bits 1. So the same, $$(2^{k}-1)$$ is k bits 1

$\therefore$ If N(x) is a negative binary integer, the most-significant bit can be repeated in all the extra bits 

$\blacksquare$ 




