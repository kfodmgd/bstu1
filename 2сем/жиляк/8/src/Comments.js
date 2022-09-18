import React from "react";
import { Component } from "react";

export class Comments extends Component {
  constructor(props) {
    super(props);
    this.state = {
      img: "",
      comments: [],
      delete: null,
      edit: null,
      info: null,
    };
  }
  avatars = [
    {
      img: "",
      name: "Авка",
    },
    {
      img: "/avatars/герберы.jpg",
      name: "Герберы",
    },
    {
      img: "/avatars/ромашка.jpg",
      name: "Ромашка",
    },
    {
      img: "/avatars/гортензия.jpg",
      name: "Гортензия",
    },
    {
      img: "/avatars/розы.jpg",
      name: "Роза",
    },
  ];
  onSubmit = (e) => {//е передаётся по спецификации w3c
    e.preventDefault();//отмена события если такое возможно =>действие по умолчанию не произойдёт
    let comment = {
      name: this.name.value,
      avatar: this.state.img,
      email: this.email.value,
      message: this.message.value,
      secretWord: this.secretWord.value,
      date: new Date(),
    };
    this.setState({
      comments: [...this.state.comments, comment],//заполнение комментариями+текущим
    });
    this.name.value = null;
    this.email.value = null;
    this.message.value = null;
    this.secretWord.value = null;
    
  };
  comments() {
    return this.state.comments.map((comment) => {
      return (
        <div key={comment.message}>
          <button onClick={() => this.setState({ edit: comment, delete: null, info: null })}>Ред.</button>
          {comment === this.state.edit ? 
          <CommentsEdit 
            comment={this.state.edit}
            editComment={this.editComment}
          />
           : null}
          <button onClick={() => this.setState({ delete: comment, edit: null, info: null })}>
            Удалить
          </button>
          {comment === this.state.delete ? (
            <CommentsDel
              deleteComment={this.deleteComment}
              comment={this.state.delete}
            />
          ) : null}
          <button  onClick={() => this.setState({ info: comment, edit: null, delete: null })}>Инфо</button>
          {comment === this.state.info ? (
            <CommentsInfo comment={this.state.info} />
          ) : null}
          <div className="name">Пользователь:{comment.name}</div>
          <div className="message">Комментарий:{comment.message}</div>
          <img className="bottom"
            style={{ height: "150px", width: "150px" }}
            src={comment.avatar}
            alt=""
          />
        </div>
      );
    });
  }
  deleteComment = (comment) => {
    for (let i = 0; i < this.state.comments.length; i++) {
      if (this.state.comments[i] === comment) {
        return this.setState(({ comments }) => ({
          comments: [...comments.slice(0, i), ...comments.slice(i + 1)],
          delete: null
        }));
      }
    }
  };
  editComment = (comment, text) => {
    for (let i = 0; i < this.state.comments.length; i++) {
      if (this.state.comments[i] === comment) {
        comment.message = text;
        comment.date = new Date();
        return this.setState(({ comments }) => ({
          comments: [...comments.slice(0, i), comment, ...comments.slice(i + 1)],
          edit: null
        }));
      }
    }
  }
  render() {
    return (
      <>
        <form onSubmit={this.onSubmit}>
          <input
            ref={(e) => (this.name = e)}
            type="text"
            placeholder="Имя пользователя"
            name=""
          />
          <select onChange={(e) => this.setState({ img: e.target.value })}>
            {this.avatars.map((avatar) => {
              return (
                <option key={avatar.img} value={avatar.img}>
                  {avatar.name}
                </option>
              );
            })}
          </select>
          <img className="photo"
            style={{ height: "150px", width: "150px" }}
            src={this.state.img}
            alt=""
          />
          <input
            ref={(e) => (this.email = e)}
            type="email"
            placeholder="Email"
          />
          <textarea placeholder="Комментарий" ref={(e) => (this.message = e)} />
          <input
            ref={(e) => (this.secretWord = e)}
            type="text"
            placeholder="Секретное слово"
          />
          <input className="button" type="submit" value="Отправить" />
        </form>
        {this.comments()}
      </>
    );
  }
}

class CommentsDel extends Component {
  onSubmit = (e) => {
    e.preventDefault()
    if (this.yourWord.value === this.props.comment.secretWord) {
      return this.props.deleteComment(this.props.comment);
    }
    alert("Неправильное секретное слово!")
  }
  render() {
    return (
      <form onSubmit={this.onSubmit}>
        <input
          type="text"
          ref={(e) => (this.yourWord = e)}
          placeholder="Секретное слово"
        />
        <input type="submit" value="Подтвердить" />
      </form>
    );
  }
}
class CommentsEdit extends Component {
  onSubmit = e => {
    e.preventDefault()
    this.props.editComment(this.props.comment, this.yourComment.value)
  }
  render() {
    return (
      <form onSubmit={this.onSubmit}>
        <div className="name">Пользователь:{this.props.comment.name}</div>
        <div className="message">Email:{this.props.comment.email}</div>
        <textarea ref={(e) => (this.yourComment = e)} defaultValue={this.props.comment.message} />
        <input type="submit" value="Подтвердить" />
      </form>
    )
  }
}
class CommentsInfo extends Component {
  render() {
    let comment = this.props.comment;
    return (
      <>
        <div className="name">Пользователь:{comment.name}</div>
        <div className="date">Дата изменения:{comment.date.toLocaleString()}</div>
        <div className="message">Email:{comment.email}</div>
      </>
    );
  }
}
