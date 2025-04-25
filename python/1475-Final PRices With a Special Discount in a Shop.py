class Solution(object):
  def finalPrices(self, prices):
    """
    :type prices: List[int]
    :rtype: List[int]
    """
    ret = prices
    for i, priceI in enumerate(prices):
      for j, priceJ in enumerate(prices[i+1:]):
        if priceJ <= priceI:
          ret[i] = priceI - priceJ
          break
    return ret