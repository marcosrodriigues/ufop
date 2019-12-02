import { Component, OnInit } from '@angular/core';
import { UserService } from 'src/app/service/user.service';

@Component({
  selector: 'app-footer',
  templateUrl: './footer.component.html',
  styleUrls: ['./footer.component.css']
})
export class FooterComponent implements OnInit {

  isLogged = false;

  constructor(private _userService : UserService) { }

  ngOnInit() {
    this.isLogged = this._userService.isLogged();
  }

  ngOnChanges() {
    this.isLogged = this._userService.isLogged();
  }

  logout() {
    this._userService.logout();
  }

}
