import { Component, OnInit } from '@angular/core';
import { UserService } from 'src/app/service/user.service';

@Component({
  selector: 'app-header',
  templateUrl: './header.component.html',
  styleUrls: ['./header.component.css']
})
export class HeaderComponent implements OnInit {

  isLogged = false;

  menu : any = [];

  constructor(private _userService : UserService) { }

  ngOnInit() {
    this.isLogged = this._userService.isLogged();
  }

  logout() {
    this._userService.logout();
  }
}
