export const TableRaw = (object, index) => {
    return [
    <tr>
        <td> {index + 1} </td>
        <td> {object.name} </td>
        <td> {object.price} </td>
        <td><img width="50px" height="50px" src={object.img} alt=""/></td>
        <td><span style={{wordBreak: "break-all" }}>{object.desc}</span></td>
\        <td>{object.discount}</td>
    </tr>

];


}