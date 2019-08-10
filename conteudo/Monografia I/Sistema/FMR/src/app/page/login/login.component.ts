import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.css']
})
export class LoginComponent implements OnInit {

  constructor() { }

  ngOnInit() {
  }

  signIn() {
    console.log("signIn");
    window.localStorage['username'] = "username";
    window.location.href='';
  }

  signUp() {
    console.log("signUp");
  }

}
