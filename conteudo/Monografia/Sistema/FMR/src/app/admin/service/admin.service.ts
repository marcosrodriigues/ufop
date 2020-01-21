import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';

@Injectable({
  providedIn: 'root'
})
export class AdminService {

  private base_url = "http://localhost:8080/admin";

  constructor(private _http : HttpClient) { }

  public initState() {
    return this._http.get(this.base_url + '/state');
  }

  public initReps() {
    return this._http.get(this.base_url + '/republicas');
  }

  public initEstudantes() {
    return this._http.get(this.base_url + '/estudantesSemRepublica');
  }

  public aprovar(morador_id) {
    return this._http.post(this.base_url + '/republica/setAprovado/' + morador_id, { id : morador_id });
  }

  public remove(morador_id) {
    return this._http.post(this.base_url + '/republica/setPendente/' + morador_id, { id : morador_id });
  }

  public updatePersonalidade(republica_id: any) {
    return this._http.post(this.base_url + '/republica/updatePersonalidade/' + republica_id , { id : republica_id });
  }

  public recomendar(user_id: any) {
    return this._http.get(this.base_url + '/recomendar/' + user_id);
  }
}
