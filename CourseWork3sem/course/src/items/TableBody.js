import {TableRaw} from "./TableRaw";

export const TableBody = ({array}) => {

    return (
        <tbody>
        {array.map(TableRaw)}
        </tbody>
    )
}