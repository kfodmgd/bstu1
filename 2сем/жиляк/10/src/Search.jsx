import React from "react";
export class Search extends React.Component {
  onChange = (e) => {
    this.setState(() => this.props.search(e.target.value));
  };
  onClick = (target) => {
    this.setState(() => this.props.searchParameter(target));
  };
  render() {
    return (
      <div className="search">
        <input type="search" placeholder="Search..." onChange={this.onChange} />
        <label>
          <input
            type="radio"
            id="partial"
            name="search"
            defaultChecked
            onClick={this.onClick.bind(this, "partial")}
          />
          partial match
        </label>
        <label>
          <input
            type="radio"
            id="full"
            name="search"
            onClick={this.onClick.bind(this, "full")}
          />
          full match
        </label>
      </div>
    );
  }
}
