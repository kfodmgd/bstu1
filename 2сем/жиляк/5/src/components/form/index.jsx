import React from "react";

import {SignUpEmailInput} from './SingUpEmailInput'
import {SignUpPasswordInput} from './SingUpPasswordInput'
import {PhoneInput} from './PhoneInput'
import './index.css';

export default class Form extends React.Component{

    static defaultProps={
        years:[1950,1951,1952,1953,1954,1955,1956,1957,1958,1959,1960,1961,1962,1963,1964,1965,1966,1967,1968,1969,1970,1971,1972,1973,1974,1975,1976,1977,1978,1979,1980,1981,1982,1983,1984,1985,1986,1987,1988,1989,1990,1991,1992,1993,1994,1995,1996,1997,1998,1999,2000,2001,2002,2003,2004],
        monthNames:['Январь','Февраль','Март','Апрель','Май','Июнь','Июль','Август','Сентябрь','Октябрь','Ноябрь','Декабрь'],
        day:[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31],
    };

    state = {
        disableBtn: false,
    }
    disableBtn = (value) => {
        this.setState({disableBtn: value})
        return this.state.disableBtn
    }
    render() {
        const {years,monthNames,day}=this.props;
        return(
            <form>
                <SignUpEmailInput disableBtn={this.disableBtn} />
                <br/>
                <SignUpPasswordInput disableBtn={this.disableBtn} />
                <br/>
                <input type="text" placeholder="Фамилия" />
                <br/>
                <input type="text" placeholder="Имя" />
                <br/>
                <input type="text" placeholder="Отчество" />
                <br/>
                <input type="radio" name="gender" value="male" />муж
                <input type="radio" name="gender" value="female" />жен
                <br/>
                <div className="date">
                <label>День рождения:</label><select>
                    {day.map(day=>
                        <option key={day} value={day}>{day}</option>    
                    )}
                </select>
                <select>
                    {monthNames.map((name,index)=>
                        <option key={name} value={index}>{name}</option>
                    )}
                </select>
                <select>
                    {years.map(year=>
                        <option key={year} value={year}>{year}</option>
                    )}
                </select>
                </div>
                <br />
                <PhoneInput />
                <br />
                <button disabled={this.state.disableBtn} onClick={this.handleBtnClick}>Отправить</button>
            </form>
        )
    }
}