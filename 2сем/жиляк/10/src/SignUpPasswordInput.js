import React from "react";

export class SignUpPasswordInput extends React.Component {
  state = {
    password: "",
    disableBtn: true,
  };
  handlePassword = (e) => {
    this.setState({ password: e.target.value });
  };

  handleRepeat = (e) => {
    this.state.password === e.target.value
      ? this.setState({ disableBtn: false }, () =>
          this.props.disableBtn(this.state.disableBtn)
        )
      : this.setState({ disableBtn: true }, () =>
          this.props.disableBtn(this.state.disableBtn)
        );
  };
  checkPassword() {
    let check = 0,
      text;
    if (this.state.password.match(/\d/g) || this.state.password.match(/[a-z]/g))
      check++;
    if (this.state.password.match(/[A-Z]/g)) check++;
    if (this.state.password.match(/\W/g)) check++;
    switch (check) {
      case 0:
        return (text = "Пароль пуст");
      case 1:
        if (this.state.password.length > 7) return (text = "Надежный пароль");
        return (text = "Ненадежный пароль");
      case 2:
        if (this.state.password.length > 5) return (text = "Надежный пароль");
        return (text = "Ненадежный пароль");
      case 3:
        if (this.state.password.length > 5)
        return (text = "Очень надежный пароль");
        return (text = "Ненадежный пароль");
    }
    return <div>{text}</div>;
  }
  render() {
    return (
      <>
        <input
          type="password"
          placeholder="Введите пароль"
          onChange={this.handlePassword}
        />
        {this.checkPassword()}
        <input
          type="password"
          placeholder="Повторите пароль"
          onChange={this.handleRepeat}
        />
      </>
    );
  }
}
