import {ArrowButtons} from "./ArrowButtons";

export const TableHeader = ({handler}) => {
    return (
        <thead>
        <tr>
            <th>
                <div className="head-items">
                    <span>Number</span>
                </div>
            </th>
            <th>
                <div className="head-items">
                    <span>Name</span>
                    <ArrowButtons arrowAttribute="name" handler={handler}/>
                </div>
            </th>
            <th>
                <div className="head-items">
                    <span>Price</span>
                    <ArrowButtons arrowAttribute="price" handler={handler}/>
                </div>
            </th>
            <th>
                <div className="head-items">
                    <span>Image</span>
                </div>
            </th>
            <th>
                <div className="head-items">
                    <span>Description</span>
                </div>
            </th>
            <th>
                <div className="head-items">
                    <span>Discount</span>
                    <ArrowButtons arrowAttribute="Discount" handler={handler}/>
                </div>
            </th>


        </tr>
        </thead>
    )

}