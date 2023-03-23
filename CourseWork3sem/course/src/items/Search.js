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
            <div>
                <input className="search" type="search" placeholder="Search..." onChange={this.onChange}/>
            </div>
        );
    }
}
