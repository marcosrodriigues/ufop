import { Component, OnInit } from '@angular/core';
import { UserService } from 'src/app/service/user.service';

@Component({
  selector: 'app-excluir-conta',
  templateUrl: './excluir-conta.component.html',
  styleUrls: ['./excluir-conta.component.css']
})
export class ExcluirContaComponent implements OnInit {

  constructor(private _userService : UserService) { }

  ngOnInit() {
  }

  delete() {
    this._userService.delete().subscribe(data => {
      alert('Usuário Deletado');
      this._userService.logout();
      
    })
  }
}
