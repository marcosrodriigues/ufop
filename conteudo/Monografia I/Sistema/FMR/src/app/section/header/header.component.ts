import { Component, OnInit } from '@angular/core';
import { UserService } from 'src/app/service/user.service';

@Component({
  selector: 'app-header',
  templateUrl: './header.component.html',
  styleUrls: ['./header.component.css']
})
export class HeaderComponent implements OnInit {

  isLogged = false;

  constructor(private _userService : UserService) { }

  ngOnInit() {
    if (this._userService.getToken() != '') {
      this.isLogged = true;
    }
  }

  logout() {
    this._userService.logout();
  }

}
