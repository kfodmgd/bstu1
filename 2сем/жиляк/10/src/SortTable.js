import { Component } from "react";

export class SortTable extends Component {
  constructor(props) {
    super(props);
    this.sorted = { name: true, price: true, inStock: true, discount: true};
    this.state = { array: this.goods };
  }
  
  goods = [
    { id: "Milk", name: "Milk", price: 0.8, inStock: 4, img: "/imgs/milk.jpg", desc: "Молоко-Калории, ккал: 64;Белки, г: 3.2; Жиры, г: 3.6; Углеводы, г: 4.8;", new: true, discount: 20 },
    { id: "Butter", name: "Butter", price: 1.3, inStock: 13, img: "/imgs/butter.jpg", desc: "Масло сливочное-Калории, ккал: 748;Белки, г: 0.5; Жиры, г: 82.5; Углеводы, г: 0.8;", new: true, discount: 10 },
    { id: "Coffee", name: "Coffee", price: 12, inStock: 23, img: "/imgs/coffee.jpg", desc: "Какао порошок-Калории, ккал: 374;Белки, г: 24.2; Жиры, г: 17.5; Углеводы, г: 31.9;", new: false, discount: 40 },
    { id: "Tea", name: "Tea", price: 13, inStock: 2, img: "/imgs/tea.jpg", desc: "Чай чёрный-Калории, ккал: 0;Белки, г: 0.1; Жиры, г: 0; Углеводы, г: 0;", new: false, discount: 15 },
    { id: "Sugar", name: "Sugar", price: 1.2, inStock: 0, img: "/imgs/sugar.jpg", desc: "Сахар-песок-Калории, ккал: 398;Белки, г: 0; Жиры, г: 0; Углеводы, г: 99.7;", new: false, discount: 30 },
    { id: "Apples", name: "Apples", price: 1, inStock: 16, img: "/imgs/apples.jpg", desc: "Яблоки наливные-Калории, ккал: 47;Белки, г: 0.4; Жиры, г: 0.4; Углеводы, г: 9.8;", new: false, discount: 25 },
    { id: "Cheese", name: "Cheese", price: 10, inStock: 9, img: "/imgs/cheese.jpg", desc: "Сыр 'чёрный граф'-Калории, ккал: 363;Белки, г: 24.1; Жиры, г: 29.5; Углеводы, г: 0.3;", new: false, discount: 5 },
  ];
  styles = {
    td: {
      padding: "10px 20px",
      border: "1px solid",
    },
    table: {
      margin: "100px",
      borderCollapse: "collapse",
    },
  };
  sort(byWhat) {
    let direction = this.sorted[byWhat] ? 1 : -1,
      goodsCopy = [...this.goods].sort(function (a, b) {
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
  table() {
    let stringNumber = 0;
    return this.state.array.map((item) => {
      let inStockStyle = {};
      if (+item.inStock < 3) inStockStyle = { background: "yellow" };
      if (+item.inStock === 0) inStockStyle = { background: "red" };
      return (
        <tr key={item.id}>
          <td style={this.styles.td}>{++stringNumber}</td>
          <td style={this.styles.td}>{item.name}</td>
          <td style={this.styles.td}>${item.price}</td>
          <td style={Object.assign({}, this.styles.td, inStockStyle)}>
            {item.inStock}
          </td>
          <td style={this.styles.td}><img src={item.img} style={{width: "50px"}} alt=""/></td>
          <td style={this.styles.td}>{item.desc}</td>
          <td style={this.styles.td}>{item.new ? "Yes" : "No"}</td>
          <td style={this.styles.td}>{item.discount}%</td>
        </tr>
      );
    });
  }
  head = [
    <tr>
      <td style={this.styles.td}>№</td>
      <td style={this.styles.td}>
        <button onClick={() => this.sort("name")}>Name</button>
      </td>
      <td style={this.styles.td}>
        <button onClick={() => this.sort("price")}>Price</button>
      </td>
      <td style={this.styles.td}>
        <button onClick={() => this.sort("inStock")}>In Stock</button>
      </td>
      <td style={this.styles.td}>Image</td>
      <td style={this.styles.td}>Description</td>
      <td style={this.styles.td}>Is New</td>
      <td style={this.styles.td}>
        <button onClick={() => this.sort("discount")}>Discount</button>
      </td>
    </tr>,
  ];
  render() {
return null
  }
}
