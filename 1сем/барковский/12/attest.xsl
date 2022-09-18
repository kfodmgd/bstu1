<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
 <html>
 <body>
 <h2>Attestation</h2>
 <table border="1">
 <tr>
 <th>name</th>
 <th>mark</th>
 </tr>

<!-- &gt; когда больше значения           &lt;-меньше-->
<xsl:for-each select="attestation/child">
 <tr>
 <td><xsl:value-of select="name"/></td><!--грубо говоря это первая колонка в таблице-->
 <xsl:choose>
 <xsl:when test="mark &lt; 4"><!--проверка mark  если меньше 4, то фон красится-->
 <td bgcolor="red">
 <xsl:value-of select="mark"/> </td>
  </xsl:when>
 <xsl:when test="mark &gt; 8">
  <td bgcolor="green">
 <xsl:value-of select="mark"/> </td><!--то где надо применить свойства(просто отсеиваем нужные атрибуты и заменяем там фон)+обозначаем что нам надо туда пометить с красным фоном-->
 </xsl:when>




 <xsl:otherwise>
 <td><xsl:value-of select="mark"/></td><!--грубо говоря это вторая колонка в таблице-->
 </xsl:otherwise>
 </xsl:choose>
 </tr>
 </xsl:for-each>


 </table>
 </body>
 </html>
</xsl:template>
</xsl:stylesheet>