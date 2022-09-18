<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
 <html>
 <body>
 <h2>history of the server 2b2t year by year</h2>
 <table border="1">
 <tr bgcolor="rgb(31, 48, 94)">
 <th>year</th>
 <th>events</th>
 </tr>
 <xsl:for-each select="server2b2t/period"><!--где будем выполнять сортировку-->
 <xsl:sort select="year" order="ascending"/><!--для чего будем выполнять сортировку и как-->
 <tr>
 <td><xsl:value-of select="year"/></td><!--заполнение таблицы+параллельное создание ячеек под необхожимые данные-->
 <td><xsl:value-of select="era"/></td><!--как и выше выбираем данные из всего файл xml и записываем его в ячейку-->
 </tr>
 </xsl:for-each>
 </table>
 </body>
 </html>
</xsl:template>
</xsl:stylesheet>