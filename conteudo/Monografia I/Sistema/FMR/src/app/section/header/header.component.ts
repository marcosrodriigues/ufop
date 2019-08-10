import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-header',
  templateUrl: './header.component.html',
  styleUrls: ['./header.component.css']
})
export class HeaderComponent implements OnInit {

  isLogged = false;

  constructor() { }

  ngOnInit() {
    if (window.localStorage['username'] != '') {
      this.isLogged = true;
    }
  }

  logout() {
    window.localStorage['username'] = '';
    window.location.href='';
  }

}
