import { SortTable } from "./SortTable.js";
import React, { Component } from "react";

export class Catalog extends Component {
  constructor(props) {
    super(props);
    this.sortTableRef = React.createRef();//создаём реф 
    this.state = { loaded: false};
    this.sorted = { name: true, price: true, inStock: true, discount: true};
  }
  componentDidMount() {
    this.setState({ loaded: true, array: this.sortTableRef.current.goods});//устанавливаем фокус для рефа
  }
  sort(byWhat) {
    let direction = this.sorted[byWhat] ? 1 : -1,
      goodsCopy = [...this.sortTableRef.current.goods].sort(function (a, b) {
        if (a.new || b.new)
        return 0
        if (a[byWhat] > b[byWhat]) {
          return direction;
        }
        if (a[byWhat] < b[byWhat]) {
          return direction * -1;
        }
        return 0;
      });
    this.sorted[byWhat] = !this.sorted[byWhat];
    this.setState({ array: goodsCopy });
  }
  sorts() {   
    return (
      <div className="sorts">
        <button onClick={() => this.sort("name")}>
          Name
        </button>
        <button onClick={() => this.sort("price")}>
          Price
        </button>
        <button onClick={() => this.sort("inStock")}>
          In Stock
        </button>
        <button onClick={() => this.sort("discount")}>
          Discount
        </button>
      </div>
    );
  }
  goods() {
   console.log() 
    return this.state.array.map((item) => {
      return (
        <div className="one_good">
          <img src={item.img} alt="" />
          <div className="text">
            <div className="discount">
                {item.new && <h2 className="new">New</h2>}
                <h2 className="minus">Discount -{item.discount}%</h2>
            </div>
            <h2>{item.name}</h2>
            <div className="prices">
            {item.discount && <h2>{(item.price * (100 - item.discount)) / 100}$</h2>}
            <h3>{item.price}$</h3>
            </div>
            <h4>Available: {item.inStock} items</h4>
            <div>{item.desc}</div>
          </div>
        </div>
      );
    });
  }
  render() {
    return (
      <>
        {this.state.loaded && this.sorts()}
        {this.state.loaded && this.goods()}
        <SortTable ref={this.sortTableRef} />
      </>
    );
  }//ref хранит ссылку на опред узел в доме
}
