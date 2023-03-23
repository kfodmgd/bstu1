import {useState} from "react";
import {TableHeader} from "./TableHeader";
import {TableBody} from "./TableBody";
import react from "react";
import "../../src/style/css/sortTable.css"

export const SortTable = ({content}) => {

    const [array, setArray] = useState(content);

    const sortTable = (sortingValue, sortType) => {

        const direction = sortType === "ascending" ? 1 : -1;
        const currentContent = array;
        let newContent;

        switch (sortingValue) {
            case "price":
                newContent = currentContent.sort((a, b) => (a.price - b.price) * direction);
                break;
            case "inStock":
                newContent = currentContent.sort((a, b) => (a.inStock - b.inStock) * direction);
                break;
            case "name":
                newContent = currentContent.sort((a, b) => a.name > b.name);
                if (direction === -1) newContent.reverse();
                break;
            case "Discount":
                newContent = currentContent.sort((a, b) => (a.discount - b.discount) * direction);
                break;
        }
        setArray([...newContent]);
    }

    return (
        <table>
            <TableHeader handler={sortTable}/>
            <TableBody array = {array}/>
        </table>
    );

}
